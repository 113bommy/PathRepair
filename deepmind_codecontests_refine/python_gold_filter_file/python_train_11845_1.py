N,M = map(int,input().split())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
MOD = 998244353

class Convolution:
    def __init__(self):
        pass

    def _ceil_pow2(self, n):
        assert n >= 0
        x = 0
        while (1<<x) < n:
            x += 1
        return x

    def _bsf(self, n):
        assert n >= 1
        return len(bin(n & -n)) - 3

    def _butterfly(self,a,mod):
        n = len(a)
        h = self._ceil_pow2(n)
        self.sum_e = [0] * 30
        es = [0] * 30
        ies = [0] * 30
        cnt2 = self._bsf(mod - 1)
        g = 3 #primitive_root ??
        e = pow(g, (mod-1)>>cnt2, mod)
        ie = pow(e,mod-2,mod)
        for i in range(cnt2,1,-1):
            es[i-2] = e
            ies[i-2] = ie
            e *= e
            e %= mod
            ie *= ie
            ie %= mod
        now = 1
        for i in range(cnt2 - 2):
            self.sum_e[i] = (es[i] * now) % mod
            now *= ies[i]
            now %= mod
        for ph in range(1,h+1):
            w = 1 << (ph-1)
            p = 1 << (h-ph)
            now = 1
            for s in range(w):
                offset = s << (h - ph + 1)
                for i in range(p):
                    l = a[i + offset]
                    r = a[i + offset + p] * now
                    a[i + offset] = (l+r) % mod
                    a[i + offset + p] = (l-r) % mod
                now *= self.sum_e[self._bsf(((1<<32)-1)^s)]
                now %= mod

    def _butterfly_inv(self,a,mod):
        n = len(a)
        h = self._ceil_pow2(n)
        self.sum_ie = [0] * 30
        es = [0] * 30
        ies = [0] * 30
        cnt2 = self._bsf(mod - 1)
        g = 3 #primitive_root ??
        e = pow(g, (mod-1)>>cnt2, mod)
        ie = pow(e,mod-2,mod)
        for i in range(cnt2,1,-1):
            es[i-2] = e
            ies[i-2] = ie
            e *= e
            e %= mod
            ie *= ie
            ie %= mod
        now = 1
        for i in range(cnt2 - 2):
            self.sum_ie[i] = (ies[i] * now) % mod
            now *= es[i]
            now %= mod
        for ph in range(h,0,-1):
            w = 1 << (ph-1)
            p = 1 << (h-ph)
            inow = 1
            for s in range(w):
                offset = s << (h - ph + 1)
                for i in range(p):
                    l = a[i + offset]
                    r = a[i + offset + p]
                    a[i + offset] = (l+r) % mod
                    a[i + offset + p] = ((l-r) * inow) % mod
                inow *= self.sum_ie[self._bsf(((1<<32)-1)^s)]
                inow %= mod

    def convolution_mod(self, a, b, mod):
        n,m = len(a),len(b)
        if n==0 or m==0: return []
        if min(n,m) <= 60:
            if n < m:
                a,b,n,m = b,a,m,n
            ans = [0] * (n+m-1)
            for i in range(n):
                for j in range(m):
                    ans[i+j] += a[i] * b[j]
                    ans[i+j] %= mod
            return ans
        z = 1 << self._ceil_pow2(n+m-1)
        a += [0] * (z-n)
        self._butterfly(a,mod)
        b += [0] * (z-m)
        self._butterfly(b,mod)
        for i in range(z):
            a[i] *= b[i]
            a[i] %= mod
        self._butterfly_inv(a,mod)
        a = a[:n+m-1]
        iz = pow(z,mod-2,mod)
        for i in range(n+m-1):
            a[i] *= iz
            a[i] %= mod
        return a

ans = Convolution().convolution_mod(A,B,MOD)
print(*ans)
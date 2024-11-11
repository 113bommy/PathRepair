K, N = list(map(int, input().split()))

dprint = lambda *x:x

def cmb(n, r, mod):
    if ( r<0 or r>n ):
        return 0
    r = min(r, n-r)
    return g1[n] * g2[r] * g2[n-r] % mod

mod = 998244353 #出力の制限
__N = 8000
g1 = [1, 1] # 元テーブル
g2 = [1, 1] #逆元テーブル
inverse = [0, 1] #逆元テーブル計算用テーブル

for i in range( 2, __N + 1 ):
    g1.append( ( g1[-1] * i ) % mod )
    inverse.append( ( -inverse[mod % i] * (mod//i) ) % mod )
    g2.append( (g2[-1] * inverse[-1]) % mod )



def kumiawase(p, q):
    # dprint(p,q,cmb(p+q-1,q-1 ,mod))
    return cmb(p+q -1,q-1 ,mod)


def solve(n):
    assert n <= K+1
    # 組み合わせの組
    # abs(n-1)//2 + 偶数分 n//2?
    # 2 ->  1,1
    # 3 -> 1,2
    # 4 -> 1,3 2,2
    # 5 -> 1,4 2,3
    # 6 -> 1,5 2,4 3,3
    # 7  3通り

    # 組のうち片方だけ使用する数 p
    ans = 0
    kumi = (n - 1) // 2
    for p in range(kumi+1):
        # dprint("p",p,"n",n)
        if p>N:
            break
        # 使えるのは p個 + 組に関係ないやつ
        ans += 2**p *cmb(kumi,p,mod)* kumiawase(N - p, p+ (K-kumi*2- int(n%2==0) ) )
        # dprint("anstmp1",ans)
        if n % 2 == 0 and N - p -1 >= 0:
            ans += 2**p *cmb(kumi,p,mod) * kumiawase(N - p -1 , p+ (K-kumi*2- int(n%2==0) ) ) # K==n//2を使用
    # dprint("-------",ans)
    return ans


ans = []
for i in range(2, 2 * K +1):
    if i <= K+1:
        tmp = solve(i)%998244353
        ans.append(tmp)
        print(tmp)
    else:
        print(ans[-i + K])

import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")



### 遅延評価セグメント木
class LazySegmentTree:
    def __init__(self, n, a=None):
        """初期化
        num : n以上の最小の2のべき乗
        """
        num = 1
        v = 0
        while num<=n:
            num *= 2
            v += 1
        self.q = [None]*(2*v+10)
        self.num = num
        self.seg = [ninf] * (2*self.num-1)
        self.lazy = [f0] * (2*self.num-1)
        self.ls = [0]*(2*self.num-1)
        self.rs = [0]*(2*self.num-1)
        self.ls[0] = 0
        self.rs[0] = self.num
        for i in range(self.num-1):
            self.ls[2*i+1] = self.ls[i]
            self.rs[2*i+1] = (self.ls[i] + self.rs[i])//2
            self.ls[2*i+2] = (self.ls[i] + self.rs[i])//2
            self.rs[2*i+2] = self.rs[i]
        if a is not None:
            # O(n)で初期化
            assert len(a)==n
            for i in range(n):
                self.seg[num-1+i] = a[i]
            for k in range(num-2, -1, -1):
                self.seg[k] = op(self.seg[2*k+1], self.seg[2*k+2])
    def eval(self, k):
        if self.lazy[k]==f0:
            return 
        if k<self.num-1:
            self.lazy[k*2+1] = composition(self.lazy[k], self.lazy[k*2+1])
            self.lazy[k*2+2] = composition(self.lazy[k], self.lazy[k*2+2])
        self.seg[k] = mapping(self.lazy[k], self.seg[k])
        self.lazy[k] = f0
    def eval_all(self):
        for i in range(2*self.num-1):
            self.eval(i)
    def update(self,a,b,x=None,f=None):
        """A[a]...A[b-1]をxに更新する
        """
        if f is None:
            # 更新クエリ
            f = lambda y: x
        k = 0
        self.q[0] = k # k>=0なら行きがけ順
        ind = 1
        # 重なる区間を深さ優先探索
        while ind:
            ind -= 1
            k = self.q[ind]
            l,r = self.ls[k], self.rs[k]
            if k>=0:
                self.eval(k)
                if r<=a or b<=l:
                    continue
                elif a<=l and r<=b:
                    self.lazy[k] = composition(f, self.lazy[k])
                    self.eval(k)
                else:
                    self.q[ind] = ~k
                    self.q[ind+1] = 2*k+1
                    self.q[ind+2] = 2*k+2
                    ind += 3
#                     q.append(~k)
#                     q.append(2*k+1)
#                     q.append(2*k+2)
            else:
                k = ~k
                self.seg[k] = op(self.seg[2*k+1], self.seg[2*k+2])
    def query(self,a,b):
        k = 0
        l = 0
        r = self.num
        self.q[0] = k
        ind = 1
        ans = ninf
        # 重なる区間を深さ優先探索
        while ind:
            ind -= 1
            k = self.q[ind]
            l,r = self.ls[k], self.rs[k]
            self.eval(k)
            if r<=a or b<=l:
                continue
            elif a<=l and r<=b:
                ans = op(ans, self.seg[k])
            else:
                self.q[ind] = 2*k+2
                self.q[ind+1] = 2*k+1
                ind += 2
#                 q.append(2*k+2)
#                 q.append(2*k+1)
#             print(q, ans, l,r,a,b, self.seg[k])
        return ans
n,q = list(map(int, input().split()))
a = list(map(int, input().split()))
# ninf = -10**9
# op = max
# mapping = lambda f,x: f(x)
# composition = lambda f1, f2: f1 if f1 is not None else f2
b1 = 20
b2 = 20
ninf = 0 # (転倒数, #0, #1)
def op(x,y):
    x0 = x>>(b1+b2)
    xx = x%(1<<(b1+b2))
    x1 = xx>>b1
    x2 = xx%(1<<b2)
    y0 = y>>(b1+b2)
    xx = y%(1<<(b1+b2))
    y1 = xx>>b1
    y2 = xx%(1<<b2)
    return ((x0+y0+x2*y1)<<(b1+b2)) + ((x1+y1)<<b1) + x2+y2
def mapping(f,x):
    if not f:
        return x
    x0 = x>>(b1+b2)
    xx = x%(1<<(b1+b2))
    x1 = xx>>b1
    x2 = xx%(1<<b2)
    return (((x1+x2)*(x1+x2-1)//2 - (x1*(x1-1)//2) - (x2*(x2-1)//2) - x0)<<(b1+b2)) + (x2<<b1) + x1

# op = lambda x,y: (x[0]+y[0]+x[2]*y[1], x[1]+y[1], x[2]+y[2])
# mapping = lambda f,x: ((x[1]+x[2])*(x[1]+x[2]-1)//2 - (x[1]*(x[1]-1)//2) - (x[2]*(x[2]-1)//2) - x[0], x[2], x[1]) if f else x
composition = lambda f1, f2: f1^f2
f0 = False
sg = LazySegmentTree(n, [((1<<b1) if item==0 else 1) for item in a])
ans = []
for _ in range(q):
    t = tuple(map(int, input().split()))
    if t[0]==1:
        _, l,r = t
        sg.update(l-1,r,f=True)
    else:
        _,l,r = t
        ans.append(sg.query(l-1,r)>>(b1+b2))
#         break
write("\n".join(map(str, ans)))
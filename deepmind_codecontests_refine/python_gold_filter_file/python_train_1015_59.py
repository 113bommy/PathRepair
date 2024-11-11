class SegTree(object):
  def __init__(self,op,e,n,init_val):
    self.num = 1<<(n-1).bit_length() 
    self.S = [e]*self.num*2
    self.op = op
    self.e = e
    for i,v in enumerate(init_val): self.S[self.num+i] = v
    for i in range(self.num-1,0,-1):
      self.S[i] = self.op(self.S[i*2], self.S[i*2+1])
      
  def set(self,index,value):
    idx = self.num+index
    self.S[idx] = value
    while idx>0:
      self.S[idx>>1] = self.op(self.S[idx],self.S[idx^1])
      idx>>=1
      
  def prod(self,l,r):
    res = self.e
    l = max(0,l)+self.num
    r = min(r,self.num-1)+self.num
    while l<r:
      if l&1:
        res = self.op(res,self.S[l])
        l += 1
      if r&1:
        res = self.op(self.S[r-1],res)
      l >>= 1
      r >>= 1
    return res
        
N,K = map(int,input().split())
ST = SegTree(max,0,300001,[0]*300001)
ans = 1
for i in range(N):
  A = int(input())
  l,r = max(0,A-K),min(A+K+1,300001)
  v = ST.prod(l,r)+1
  ans = max(ans,v)
  ST.set(A,v)
print(ans)
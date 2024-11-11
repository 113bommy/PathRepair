(n,m) = map(int,input().split())
a,A,b,me,d,w,s = [0]*m,[0]*m,[-1]*n,[1]*n,[0]*n,[0]*m,(n*(n-1))//2
for i in range(m):
    (a[i], A[i]) = map(int,input().split())
    a[i] -= 1
    A[i] -= 1
w[m-1] = s
 
def se(i, b):
     m = 0
     while b[i] >= 0:
          i = b[i]
          m += 1
     return i,m
 
for j in range(m-1):
     i = m-j-1
     i1,i2 = a[i],A[i]
     p1,m1 = se(i1, b)
     p2,m2 = se(i2, b)
     if p1 != p2:
          if d[m1] < d[m2]:
               (p1,p2) = (p2,p1)
          b[p2] = p1
          s -= me[p1]*me[p2]
          me[p1] += me[p2]
          me[p2] = 0
          d[p1] = max(d[p1],d[p2]+1)
     w[i-1] = s
         
for i in range(m):
     print(w[i])
n=int(input())
a=[list(map(int,input().split()))for _ in range(n)]
for k in range(n):
 b=a[k];b[3],b[4]=b[4],b[3]
t=0
for i in range(n-1):
 d=a[i]
 for j in range(i+1,n):
  e=a[j]
  for p in('012345','152043','215304','302541','410352','514320'):
   f=[d[int(k)]for k in p]
   if f[0]==e[0]and f[5]==e[5]:
    f=f[1:5]*2
    for k in range(4):
     if f[k:k+4]==e[1:5]:t=1
print(('Yes','No')[t])

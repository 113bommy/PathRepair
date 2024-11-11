n=int(input());e=[[]for _ in[0]*-~n];q=[(1,0)];f=[-1]*n
while n>1:v,w,c=map(int,input().split());e[v]+=(w,c),;e[w]+=(v,c),;n-=1
while q:
 v,c=q.pop();f[v-1]=c%2
 for w,d in e[v]:q+=[(w,c+d)]*(f[w-1]<0)
print(*f)
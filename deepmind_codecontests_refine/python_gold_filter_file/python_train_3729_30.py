I=lambda:list(map(int,input().split()));n,m=I();l=[I()+[i]for i in range(m)];c=[0]*-~n;a=[0]*m
for p,y,i in sorted(l,key=lambda x:x[1]):c[p]+=1;a[i]='%06d'%p+'%06d'%c[p]
for t in a:print(t)
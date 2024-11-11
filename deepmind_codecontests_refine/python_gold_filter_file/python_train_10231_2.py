def g(i,z,k):
 if i>=n:return 0
 if q[i][z][k]>-1:return q[i][z][k]
 o=g(i+1,z,k);c=s[i]!=t[0]
 if k>=c:o=max(o,g(i+1,z+1,k-c))
 c=s[i]!=t[1]
 if k>=c:o=max(o,g(i+1,z+(t[0]==t[1]),k-c)+z)
 q[i][z][k]=o;return o
I=input;n,k=map(int,I().split());s=I();t=I();q=[[[-1]*(n+1)for _ in[0]*n]for _ in[0]*n];print(g(0,0,k))
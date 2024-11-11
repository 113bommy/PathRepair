a,b,c=map(int,input().split())
d,e,f=map(int,input().split())
x=int(input())
a=(a+b+c+4)//5+(d+e+f+9)//10
if(a>x): print("NO")
else: print("YES")
n=int(input())
for _ in range(n):
     k=int(input())
     m=[0,0,0]
     l=list(map(int,input().split(" ")))
     for i in l:
          m[i%3]+=1
     res=m[0]
     s=min(m[1],m[2])
     res+=s
     ans=(m[1]+m[2]-s-s)//3
     print(res+ans)
     
     

N=int(input())
List=[[i+1]+input().split() for i in range(N)]
List.sort(key=lambda x:(x[1],-int(x[2])))
for s,r,t in List:
          print(s)
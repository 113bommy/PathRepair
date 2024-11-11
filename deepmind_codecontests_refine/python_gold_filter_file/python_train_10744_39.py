for t in range(int(input())):
     a,b,c=list(sorted(map(int,input().split())))
     if c-a-b<2:
          print("Yes")
     else:
          print("No")

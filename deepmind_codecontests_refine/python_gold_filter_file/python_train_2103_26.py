n = int(input())

for i in range(n):

    a,b,c,d,k = (int(x) for x in input().split())

    x = a/c
    if x != int(x): x = int(x)+1

    y = b/d
    if y != int(y): y = int(y)+1
    
      
    if x + y <= k:
        print(int(x), int(y))
    else:
        print(-1)


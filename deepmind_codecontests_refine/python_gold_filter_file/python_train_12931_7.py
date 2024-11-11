
nm = list(map(int,input().split(" ")))

s = input().split(" ")
t = input().split(" ")

n = int(input())

for i in range(n):
    no = int(input())
  
    if no %nm[0] == 0:
        x = nm[0]-1
    else:
        x = no % nm[0] -1

    if no % nm[1] == 0:
        y = nm[1]-1
    else:
        y = no % nm[1] -1
    
    print(s[x]+t[y])



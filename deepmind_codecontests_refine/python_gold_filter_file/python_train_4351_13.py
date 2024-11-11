al = [list(map(int, input().split())) for i in range(3)]
al = sum(al, [])
n = int(input())
bl = [int(input()) for i in range(n)]
check = [0 for i in range(9)]
 
for b in bl:
    if b in al:
        check[al.index(b)] = 1
 
if [1,1,1] in [check[:3], check[3:6], check[6:], check[0:7:3], check[1:8:3], check[2:9:3], check[0:9:4], check[2:8:2]]:
    print("Yes")
else:
    print("No")
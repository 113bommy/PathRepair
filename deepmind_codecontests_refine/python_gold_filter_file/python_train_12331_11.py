m1,k1 = 0,0
m = list(map(int,input().split()))
k = list(map(int,input().split()))
n = int(input())
for i in range(len(m)):
    m1 += m[i]
    k1 += k[i]
if (m1+4)//5 + (k1+9)//10 <= n:
    print("YES")
else:
    print("NO")
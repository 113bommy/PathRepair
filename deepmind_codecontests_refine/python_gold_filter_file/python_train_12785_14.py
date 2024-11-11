n = int(input())
ab = []
bsum = 0
for i in range(n):
    a,b = map(int,input().split(' '))
    ab.append(a + b)
    bsum += b
ab.sort(reverse = True)
print(sum(ab[0::2]) - bsum)
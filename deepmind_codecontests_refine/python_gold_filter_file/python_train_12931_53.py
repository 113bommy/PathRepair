[n, m] = map(int, input().split())
s1 = list(input().split())
s2 = list(input().split())
for _ in range(int(input())):
    num = int(input())
    print(s1[(num % n)-1]+s2[(num % m)-1])

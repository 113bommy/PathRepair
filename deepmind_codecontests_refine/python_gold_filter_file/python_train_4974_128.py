d = int(input())
c = list(map(int, input().split()))
for i in range(d):
    s = list(map(int, input().split()))
    num = max(s)
    print(s.index(num)+1)


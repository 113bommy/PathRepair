
a, b, c = list(map(int, input().split(' ')))
cnt = 0
if a == b == c:
    cnt = a%2-1
else:
    while not (a%2 or b%2 or c%2):
        cnt += 1
        a,b,c=(b+c)/2,(a+c)/2,(a+b)/2

print(cnt)

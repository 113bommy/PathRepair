n = int(input())
text = input().split(' ')
maxc = 0
for y in text:
    cnt = 0
    for x in y:
        if 'A' <= x <= 'Z':
            cnt += 1
    maxc = max(maxc, cnt) 
print(maxc)
a = int(input())
l = []
cnt = 1
l.append(input())
for i in range(a-1):
    b = input()
    if(b == l[-1]):
        continue
    else:
        cnt+=1
    l.append(b)
print(cnt)
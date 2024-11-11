a = input()
fence = int(a.split()[1])
t = 0
for f in input().split():
    if int(f) <= fence:
        t+=1
    else:
        t+=2
print(t)
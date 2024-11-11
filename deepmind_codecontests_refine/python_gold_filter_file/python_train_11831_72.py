ls = ['a', 'e', 'i', 'o', 'u']
s = input()
cnt = 0
for i in s:
    try:
        if int(i)%2: cnt+=1
    except:
        if i in ls: cnt+=1
print(cnt)

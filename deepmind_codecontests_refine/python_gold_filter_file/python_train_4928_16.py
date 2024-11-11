s = list(map(int,input().split()))
e = list(map(int,input().split()))
q = 0
p = 0
e.sort(reverse = True)
for i in range(0,s[1]):
    p = e[i]
    q = e[i+1]
p -= q
if (e.count(min(e))>=len(e)-(s[1]-1)) and (len(e)!=2):
    print('0')
else:
    print(p)
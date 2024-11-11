from itertools import permutations

n = int(input())
s = input()
t = input()
print('YES')

'''q = 'abc'
for i in permutations([0,1,2]):
    string = q[i[0]]+q[i[1]]+q[i[2]]
    if not s in string and not t in string:
        print(q[i[0]]*n+q[i[1]]*n+q[i[2]]*n)
        break'''

if s[0]==s[1] and t[0]==t[1]:
    print(('a'+'b'+'c')*n)
elif s[0]==s[1] or t[0]==t[1]:
    if s[0]==s[1]:
        s,t=t,s
    print((s[1]+s[0]+(set(('a','b','c'))-set((s[0],s[1]))).pop())*n)
else:
    q = 'abc'
    for i in permutations([0,1,2]):
        string = q[i[0]]+q[i[1]]+q[i[2]]
        if not s in string and not t in string:
            print(q[i[0]]*n+q[i[1]]*n+q[i[2]]*n)
            break

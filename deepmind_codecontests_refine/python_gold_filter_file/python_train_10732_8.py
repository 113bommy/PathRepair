l = [int(i) for i in input().split()]
n = l[0]
m = l[1]
s = input()
t = input()
st = -1
if '*' in s:
    st = s.index('*')
if len(s)>len(t)+1:
    print("NO")
    exit()
# print(s[st+1:])
# print(t[-(len(s)-st):])
if st>=0 and st<len(s)-1 and s[0:st]==t[0:st] and s[st+1:]==t[-(len(s)-st-1):]:
    print("YES")
elif st==len(s)-1 and s[0:st]==t[0:st]:
    print("YES")
elif st<0 and s==t:
    print("YES")
else:
    print("NO")

def point(s:int):
     print(s, " ", s)

t = list(map(int, input().split()))

n, k = t[0], t[1]

#  список размерностей квадрата
s = list(map(int, input().split()))
s.sort()

if k > len(s):
    print(-1)
else:
    for i in range(len(s)):
        if i+1 == k: 
           point(s[-i-1]) 
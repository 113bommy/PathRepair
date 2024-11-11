h,w,a,b = map(int, input().split())

s0 = '0'*a + '1'*(w-a)
s1 = '1'*a + '0'*(w-a)

for i in range(h-b):
    print(s0)

for i in range(b):
    print(s1)

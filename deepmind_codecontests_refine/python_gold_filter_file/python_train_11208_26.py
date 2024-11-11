k = int(input())
s = input()
k = 0
while 'xxx' in s:
    s = s.replace('xxx', 'xx', 1)
    k += 1
print(k)
    

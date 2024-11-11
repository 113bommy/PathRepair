import sys

a = [x for x in sys.stdin.readline() if x != '\n']
s = sys.stdin.readline()

i = 0
v = [0] * 10
while(s[i] != '\n'):
    v[int(s[i])] += 1
    i += 1
    
j = 9
for i in range(len(a)):
    while(v[j] == 0 and j > 0):
        j -= 1
        
    if(j > int(a[i])):
        a[i] = str(j)
        v[j] -= 1
        
print("".join(a))
        

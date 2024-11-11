v = int(input())
x = len(str(v))
s = 0
if(x == 1):
    s = v
else:
    
    s = 9+x
    while(x != 1):
        s += (v-pow(10,x-1))*x
        v = pow(10,x-1)
        x-=1
print(s)
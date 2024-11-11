a=int(input())
b=''
while a:
 b=str(a&1)+b
 a=-(a>>1)
print(b if b else 0)

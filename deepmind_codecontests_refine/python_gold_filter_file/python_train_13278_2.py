n = int(input())
s='I hate'
a=' that I love'
b=' that I hate'
for i in range(2,n+1):
    if i%2!=0:
        s=s+b
    else:
        s=s+a
s=s+' it'
print(s)
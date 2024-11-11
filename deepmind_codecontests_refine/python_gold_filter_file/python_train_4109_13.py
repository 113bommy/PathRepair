a=int(input())
b=int(input())
c=int(input())
result=[a+b+c,a+b*c,a*(b+c),a*b*c,(a+b)*c]
print(max(result))
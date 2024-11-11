n=int(input())
str="I hate "
for i in range(n-1):
    if i%2==0:
        str+="that I love "
    else:
        str+="that I hate "
print(str+"it")

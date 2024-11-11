x = int(input(), 2)
sum=0
i =0
count=0
while True:
    sum=int(pow(4,i))
    i+=1
    if (sum>=x):
        break
    else:
        count+=1
print(count)
x=input()
list1=['a','e','i','o','u','y']
y=x.lower()
for i in range(len(y)):
    if y[i] not in list1:
        print('.',y[i],end="",sep="")

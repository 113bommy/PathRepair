x=input()
x=list(x)

p=0
if len(x)>4:
    
    for i in x:
        if i.isnumeric():
            p+=1
            break
    for i in x:
        if i.isupper():
            p+=1
            break
    for i in x:
        if i.islower():
            p+=1
            break


if p==3:
    print('Correct')
else:
    print("Too weak" )

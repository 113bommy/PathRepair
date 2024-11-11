first="qwertyuiop"
second="asdfghjkl;"
third="zxcvbnm,./"
new=""
rorl=str(input())
mole=str(input())


if rorl=="R": 
    
    for x in mole:

        if x  in first:
            i=first.find(x)
            y=first[i-1]
            new=new+y
        if x in second:
            i=second.find(x)
            y=second[i-1]
            new=new+y
        if x in third:
            i=third.find(x)
            y=third[i-1]
            new=new+y
    print(new)
else:
    for x in mole:

        if x  in first:
            i=first.find(x)
            y=first[i+1]
            new=new+y
        if x in second:
            i=second.find(x)
            y=second[i+1]
            new=new+y
        if x in third:
            i=third.find(x)
            y=third[i+1]
            new=new+y
    print(new)
n=int(input())
vec=[]
if n==3:
    vec=[2,5,63]
elif n==4:
    vec=[2,3,4,9]
elif n==5:
    vec=[2,3,4,6,9]
elif n==6:
    vec=[2,3,4,6,9,12]
elif n==7:
    vec=[2,3,4,6,8,9,10]
else:
    for i in range(1,30001):
        if (i%2)*(i%3)==0:
            vec.append(i)
            if len(vec)==n//8*8:
                break
    mx=vec[-1]
    n%=8
    if n==0:
        vec2=[]
    elif n==1:
        vec2=[6]
    elif n==2:
        vec2=[2,4]
    elif n==3:
        vec2=[2,4,6]
    elif n==4:
        vec2=[2,3,4,9]
    elif n==5:
        vec2=[2,3,4,6,9]
    elif n==6:
        vec2=[2,3,4,6,9,12]
    elif n==7:
        vec2=[2,3,4,6,8,9,10]
    for i in vec2:
        vec.append(i+mx)
print(*vec)
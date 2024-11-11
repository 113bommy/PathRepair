output=[]
for __ in range(int(input())):
    x=int(input())
    if x%2==0:
        output.append(f'{x//2} {x//2}')
    else:
        output.append(f'{1} {x-1}')
for o in output:
    print(o)
n = input()
if len(n)<7:
    print('no')
    exit()
cnt=0
last_pos=0

for i in range(0, len(n))[::-1]:
    
    if n[i]=='0':
        cnt+=1
        last_pos=i
    else:
        n=n[:i]+n[i+1:]
    if cnt==6:
        break

if cnt<6 or len(n)<6:
    print('no')
    exit()

for i in n[:last_pos]:
    if i=='1':
        print('yes')
        exit()

print('no')



    

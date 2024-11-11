a,b,c,d = map(int,input().split())
r_move = b_move = k_move = 0
if(a==c or b==d):
    r_move = 1
else:
    r_move = 2
if(abs(a-c)!=abs(b-d) and (a+b)%2==(c+d)%2):
    b_move = 2
elif(abs(a-c)==abs(b-d)):
    b_move = 1
else:
    b_move = 0
if(a==c or b==d):
    k_move = max(abs(a-c),abs(b-d))
elif(abs(a-c)==abs(b-d)):
    k_move = min(abs(a-c), abs(b-d))
else:
    k_move =  max(abs(a-c),abs(b-d)) 
print(r_move, b_move, k_move)


    
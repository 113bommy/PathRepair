
n,c =  list(map( int, input().split()))
p = list(map( int, input().split()))
t = list(map( int, input().split()))
limark = 0;
time = 0;
for i  in range(0, n):
    time += t[i]
    limark += max(0, p[i] - c * time)
time = 0
rade  = 0
for i  in range(n - 1 , -1 , -1):
    time += t[i]
    rade += max(0, p[i] - c * time)
if( rade > limark):
    print("Radewoosh")
elif rade < limark:
    print("Limak")
else:
    print("Tie")

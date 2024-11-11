n  = int(input());
a = [0 for i in range(26)]
for i in range(n):
    tmp = input();
    tmp = tmp[0];
    a[ord(tmp)-97] = a[ord(tmp)-97]+ 1;

def solver(a):
    if(a%2==0):
        b = a/2;
        return b*(b-1)
    else:
        b = int(a/2);
        c = a-b;
        return (b*(b-1))/2 + (c*(c-1))/2
    
sum = 0;    
for i in range(26):
    if(a[i]!=0):
        sum = sum + solver(a[i])
print(int(sum))

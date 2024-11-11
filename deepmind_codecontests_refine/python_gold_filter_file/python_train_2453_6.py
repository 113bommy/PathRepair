a=['monday','tuesday','wednesday','thursday','friday','saturday','sunday','monday','tuesday','wednesday','thursday','friday','saturday','sunday']
s=input()
t=input()
for i in range(14):
    if(a[i]==s):
        if(a[i]==t or a[i+2]==t or a[i+3]==t):print("YES")
        else:print("NO")
        break
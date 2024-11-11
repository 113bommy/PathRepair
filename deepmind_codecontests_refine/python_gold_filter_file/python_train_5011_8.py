'''n=int(input())
p=input().rstrip()
p=list(p)
if len(p)==1:
        print(0)
        print(''.join(p))
else:
        l=[['R','G','B'],['G','B','R'],['G','R','B'],['R','B','G'],['B','R','G'],['B','G','R']]
        w=[]
        for j in range(0,len(l)):
                SS=0;
                for i in range(0,len(p)):
                        if (i)%3==0 and l[j][0]!=p[i]:
                                SS=SS+1;
                        elif i%3==1 and l[j][1]!=p[i]:
                                SS=SS+1;
                        elif i%3==2 and l[j][2]!=p[i]:
                                SS=SS+1;
                w.append(SS)
        T=min(w)
        C=w.index(T)
        S=[]
        print(T)
        for i in range(0,len(p)):
                if i%3==0:
                        S.append(l[C][0])
                elif i%3==1:
                        S.append(l[C][1])
                elif i%3==2:
                        S.append(l[C][2])
        print(''.join(S))'''


n=int(input())
p=input().rstrip()
p=list(p)
SS=0;
for i in range(0,len(p)-1):
        if p[i]==p[i+1]:
                SS=SS+1;
                if i==len(p)-2:
                        if p[i+1]=='B':
                                p[i+1]='G';
                        elif p[i+1]=='G':
                                p[i+1]='B'
                        elif p[i+1]=='R':
                                p[i+1]='G';
                else:
                        D=[]
                        D.append(p[i+2])
                        D.append(p[i])
                        if 'G' not in D:
                                p[i+1]='G'
                        elif 'B' not in D:
                                p[i+1]='B'
                        elif 'R' not in D:
                                p[i+1]='R';
print(SS)
print(''.join(p))
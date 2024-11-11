##Lenny is playing a game on a 3 × 3 grid of lights.In the beginning of the game all lights are switched on.
 ##Pressing any of the lights will toggle it and all side-adjacent lights. The goal of the game is to switch all the lights off.
 ## We consider the toggling as follows: if the light was switched on then it will be switched off, if it was switched off then it will be switched on.
##Lenny has spent some time playing with the grid and by now he has pressed each light a certain number of times.
## Given the number of times each light is pressed, you have to print the current state of each light.
mat=[[0,0,0,0,0]]
##input
for i in range(3):
    d=[0]
    col = list(map(int,input().split()));
    d.extend(col)
    d.extend([0])
    mat.append(d);
mat.append([0,0,0,0,0])
i=0
out=[[1,1,1],[1,1,1],[1,1,1]];
for n in range(1,4):
    for m in range(1,4):
        ss=0
        su=[]
        for i in range((n-1),(n+2)):
            st=[]
            for j in range(m-1,m+2):
                st.extend([mat[i][j]]);
            su.append(st);
        ss = sum(map(sum,su))
        ss = ss-(su[0][2]+su[2][0]+su[0][0]+su[2][2])
        if (ss%2)==0:
            out[n-1][m-1]=1;
        else:
            out[n-1][m-1]=0
i=0;
j=0;
for i in range(3):
    for j in range(3):
        print(out[i][j],end='');
    print('');

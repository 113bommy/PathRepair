I=input
exec(int(I())*"I();a=[f'{i} 1 {i}'for i,x,y in zip(range(1,1001),I(),I())if x!=y];print(len(a)*3,*a);")
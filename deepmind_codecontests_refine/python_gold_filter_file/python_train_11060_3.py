for s in[*open(0)][1:]:n=int(s)//2;a=range(2,4*n+1,4);print(*(['YES']+[*a]+[i+(-1)**(i//4)for
i in a],['NO'])[n%2])
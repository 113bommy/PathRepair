def function1(n,s):
    if n==1:
        return 1
    sn=max(s)
    pokemonj=0
    pokecage=[0 for i in range(sn+1)]
    for i in range(n):
        pokecage[s[i]]+=1
    maxyincage=min(pokecage[1],1)
    a = [i for i in range(sn+1)]
    a[1] = 0

    i = 2

    while i <= sn:
        if a[i] != 0:

            pokemonj=pokecage[i]
            for j in range(i*2, sn+1, i):
                a[j] = 0
                pokemonj+=pokecage[j]
            if pokemonj>maxyincage:
                maxyincage=pokemonj

        i += 1

    return(maxyincage)



def main():
    n=int(input())
    s=list(map(int,input().split()))
    print(function1(n,s))
if __name__=='__main__':
    main()



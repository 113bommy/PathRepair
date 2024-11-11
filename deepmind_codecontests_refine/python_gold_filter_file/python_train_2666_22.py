import sys
def main ():
    nbm = 0
    maxnbm = 0
    nbc = sys.stdin.readline()
    chaine = list(sys.stdin.readline())
    for loop in range(int(nbc)):
        if chaine[loop] == " ":
            if nbm > maxnbm:
                maxnbm = nbm
            nbm = 0    
        if chaine[loop].isupper():
            nbm += 1
            
    print(max(maxnbm, nbm))
main()
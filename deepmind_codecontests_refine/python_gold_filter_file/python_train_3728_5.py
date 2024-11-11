def main():
    x,y,z,k = map(int,input().split())
    lia = sorted(list(map(int,input().split())))
    lib = sorted(list(map(int,input().split())))
    lic = sorted(list(map(int,input().split())))

    li2 = sorted(list(a+b for a in lia for b in lib),reverse = True)[:k]
    li3 = sorted(list(ab + c for ab in li2 for c in lic),reverse = True)[:k]

    print('\n'.join(map(str,li3)))

main()

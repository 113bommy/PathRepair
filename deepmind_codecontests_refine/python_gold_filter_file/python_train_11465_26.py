for _ in " "*int(input()):
    c=int(input())
    k=(c+(((c**2)-4*c)**0.5))/2
    try:print('Y',round(k,12),round(c-k,12))
    except:print('N')

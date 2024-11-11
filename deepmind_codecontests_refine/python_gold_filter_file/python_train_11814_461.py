def domino(a,b):
    area_domino=2*1
    area_board=a*b
    return int(area_board/area_domino)
a,b=map(int,input().split())
print(domino(a,b))


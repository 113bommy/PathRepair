input()
_1_=sorted(list(map(int,input().split())),reverse=True)
_2_=sorted(list(map(int,input().split())),reverse=True)
print("YES" if sum([_2_[0],_2_[1]])>= sum(_1_) else "NO")
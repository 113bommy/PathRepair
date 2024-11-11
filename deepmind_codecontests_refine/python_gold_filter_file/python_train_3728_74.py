x,y,z,k = [ int(it) for it in input().split() ]
al = [ int(it) for it in input().split() ]
bl = [ int(it) for it in input().split() ]
cl = [ int(it) for it in input().split() ]

abl = [ a + b for a in al for b in bl]
abl.sort()
abl.reverse()
abl=abl[:k]

abcl = [ ab + c for ab in abl for c in cl]
abcl.sort()
abcl.reverse()
abcl=abcl[:k]
print ( "\n".join( [ str(it) for it in abcl ]) )





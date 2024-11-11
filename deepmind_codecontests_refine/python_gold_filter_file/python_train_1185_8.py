# 0.5*0.5+0.25*0.25+... = y+y^2+y^3+... (y=0.25) = y/1-y = .25/.75
# p=a/b,q=c/d,p'=1-p,q'=1-q
# pq'+p^2qq'+p^3q^2q'+... = pq'(1+pq+p^2q^2+...)=pq'/1-pq = a(d-c)/c(b-a)
a, b, c, d = map(int, input().split())
p = a / b
q = c / d
print(p / (p + q - p * q))

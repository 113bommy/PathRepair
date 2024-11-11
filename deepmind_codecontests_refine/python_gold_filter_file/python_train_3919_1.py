n = int( input() )

min_red, max_red = -1, -1
min_blue, max_blue = -1, -1

left_green, right_green = -1, -1

a = []

ans = 0

last_r, last_b, last_g = -1, -1, -1

r_edges = []
b_edges = []
g_edges = []

for i in range( n ):

    p, c = input().split()

    p = int(p)

    if c == 'R' or c == 'G':
        if last_r != -1:
            r_edges.append( p - last_r )
        last_r = p

    if c == 'B' or c == 'G':
        if last_b != -1:
            b_edges.append( p - last_b )
        last_b = p

    if c == 'G':

        ans += sum(r_edges) + sum(b_edges)

        if len(r_edges) > 0:
            max_red = max(r_edges)

        if len(b_edges) > 0:
            max_blue = max(b_edges)

        if last_g != -1:
            if (p-last_g) < (max_red+max_blue):
                ans += (p-last_g)
                ans -= (max_red+max_blue)

        r_edges = [ ]
        b_edges = [ ]

        last_g = p

ans += sum(r_edges) + sum(b_edges)

print( ans )
